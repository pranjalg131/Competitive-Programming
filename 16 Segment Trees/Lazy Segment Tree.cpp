#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int>& arr, vector<int>& tree, int start, int end,
               int treeNode) {
    if (start == end) {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

void lazyUpdateTree(vector<int>& tree, vector<int>& lazy, int start, int end,
                    int treeNode, int left, int right, int val) {
    if (start > end) {
        return;
    }

    if (lazy[treeNode]) {
        tree[treeNode] += lazy[treeNode];  // Increment the current node

        if (start < end) {  // If children exist then only.
            lazy[2 * treeNode] += lazy[treeNode];
            lazy[2 * treeNode + 1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;  // reset the lazy tree for current node
    }

    // No overlap
    if (start > right || end < left) {
        return;
    }

    // Complete overlap
    if (left <= start && end <= right) {
        tree[treeNode] += val;  // Increment the current node.

        if (start < end) {  // If children exist then only.
            lazy[2 * treeNode] += val;
            lazy[2 * treeNode + 1] += val;
        }
        return;  // Return after doing it , children will get updated when
                 // needed
    }

    // Partial Overlap
    int mid = (start + end) / 2;
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;
    lazyUpdateTree(tree, lazy, start, mid, leftChild, left, right, val);
    lazyUpdateTree(tree, lazy, mid + 1, end, rightChild, left, right, val);

    tree[treeNode] = min(tree[leftChild], tree[rightChild]);
}

int lazyQuery(vector<int>& tree, vector<int>& lazy, int start, int end,
              int treeNode, int left, int right) {
    // Firstly Updating from the lazy tree.
    if (start > end) {
        return INT_MAX;
    }

    if (lazy[treeNode]) {
        tree[treeNode] += lazy[treeNode];  // Increment the current node

        if (start < end) {  // If children exist then only.
            lazy[2 * treeNode] += lazy[treeNode];
            lazy[2 * treeNode + 1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;  // reset the lazy tree for current node
    }

    // Completely oustide the range
    if (start > right || end < left) {
        return INT_MAX;
    }

    // Completely inside the range
    if (start >= left && end <= right) {
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end) / 2;
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;
    int ans1 = lazyQuery(tree, lazy, start, mid, leftChild, left, right);
    int ans2 = lazyQuery(tree, lazy, mid + 1, end, rightChild, left, right);

    return min(ans1, ans2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1, 3, -2, 4};
    vector<int> tree(3 * arr.size());
    buildTree(arr, tree, 0, arr.size() - 1, 1);
    vector<int> lazy(3 * arr.size());

    cout << lazyQuery(tree, lazy, 0, arr.size() - 1, 1, 0, 2) << endl;

    lazyUpdateTree(tree, lazy, 0, arr.size() - 1, 1, 0, 3, 3);

    cout << lazyQuery(tree, lazy, 0, arr.size() - 1, 1, 0, 2) << endl;

    lazyUpdateTree(tree, lazy, 0, arr.size() - 1, 1, 0, 1, 2);

    cout << lazyQuery(tree, lazy, 0, arr.size() - 1, 1, 0, 2) << endl;
    cout << lazyQuery(tree, lazy, 0, arr.size() - 1, 1, 0, 1) << endl;
    cout << lazyQuery(tree, lazy, 0, arr.size() - 1, 1, 1, 1) << endl;

    cout << "Segment Tree" << endl;
    for (int i = 1; i < 12; i++) {
        cout << tree[i] << " ";
    }

    cout << "\nLazy Tree" << endl;
    for (int i = 1; i < 12; i++) {
        cout << lazy[i] << " ";
    }

    cout << endl;

    return 0;
}