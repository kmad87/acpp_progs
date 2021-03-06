#include "btree.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <stdexcept>
#include <vector>

using std::endl;
using std::cout;

using std::copy;

using std::ostream_iterator;

using std::string;

using std::domain_error;

using std::vector;

int main()
{
    string delim = "\n" + string(20, '*') + "\n";

    Node* root = build123();

    cout << "root val = " << (root -> data);
    cout << delim;
    cout << "root left = " << ((root -> left) -> data);
    cout << delim;
    cout << "root right = " << ((root -> right) -> data);
    cout << delim;

    cout << "inserting 5 into the tree. It should be added to root -> right -> right" << endl;
    root = insert(root, 5);
    cout << "(root -> right -> right) = " <<
        (((root -> right) -> right) -> data);
    cout << delim;

    int lookup_int = 1;
    cout << lookup_int << " present in btree? " << lookup(root, lookup_int);
    cout << delim;

    lookup_int = -100;
    cout << lookup_int << " present in btree? " << lookup(root, lookup_int);
    cout << delim;

    lookup_int = 5;
    cout << lookup_int << " present in btree? " << lookup(root, lookup_int);
    cout << delim;

    Node* emptyTree = NULL;
    cout << "size of emptyTree = " << size(emptyTree) << endl;
    cout << "size of current tree = " << size(root);
    cout << delim;

    Node* badBST = NULL;
    cout << "creating a bad binary search tree (Very linear)" << endl;
    for(int i = -20; i < 21; i++)
        badBST = insert(badBST, i);
    cout << "size of badBST = " << size(badBST) << endl;
    cout << "maxDepth of badBST (expected 41) = " << maxDepth(badBST) << endl;

    cout << "maxDepth of current Tree (expected 3) = " << maxDepth(root) << endl;
    cout << "maxDepth of emptyTree (expected 0) = " << maxDepth(emptyTree);

    cout << delim;

    Node* singleNodeTree = NULL;
    singleNodeTree = insert(singleNodeTree, 42);

    Node* badBST_left_linear = NULL;
    for(int i = 10; i >= -10; i--)
        badBST_left_linear = insert(badBST_left_linear, i);

    cout << "min value in singleNodeTree (expected 42) = " << minValue(singleNodeTree) << endl;
    cout << "max value in singleNodeTree (expected 42) = " << maxValue(singleNodeTree) << endl;

    cout << "min value in badBST_left_linear (expected -10) = " << minValue(badBST_left_linear) << endl;
    cout << "max value in badBST_left_linear (expected 10) = " << maxValue(badBST_left_linear) << endl;
    cout << endl;

    cout << "min value in badBST right liner (expected -20) = " << minValue(badBST) << endl;
    cout << "max value in badBST right liner (expected 20) = " << maxValue(badBST) << endl;
    cout << endl;

    cout << "min value in current tree (expected 1) = " << minValue(root) << endl;
    cout << "max value in current tree (expected 5) = " << maxValue(root) << endl;
    cout << endl;

    cout << "trying to find minimum value from an empty tree" << endl;
    try {
        cout << "min value in emptyTree = (expected exception) = " << endl <<
            "\t" << minValue(emptyTree);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }

    cout << "trying to find maximum value from an empty tree" << endl;
    try {
        cout << "max value in emptyTree = (expected exception) = " << endl << 
            "\t" << maxValue(emptyTree);
    } catch (domain_error e) {
        cout << e.what();
    }
    cout << delim;

    cout << "printing inorder traversal of emptyTree -->" << endl << "(";
    printTree(emptyTree);
    cout << ")" << endl;

    cout << "printing inorder traversal of singleNodeTree -->" << endl << "(";
    printTree(singleNodeTree);
    cout << ")" << endl;

    cout << "printing inorder traversal of badBST -->" << endl << "(";
    printTree(badBST);
    cout << ")" << endl;

    cout << "printing inorder traversal of badBST_left_linear -->" << endl << "(";
    printTree(badBST_left_linear);
    cout << ")" << endl;

    cout << "printing inorder traversal of current tree -->" << endl << "(";
    printTree(root);
    cout << ")" << delim;

    cout << "printing post order traversal of emptyTree -->" << endl << "(";
    printPostOrder(emptyTree);
    cout << ")" << endl;

    cout << "printing post order traversal of singleNodeTree -->" << endl << "(";
    printPostOrder(singleNodeTree);
    cout << ")" << endl;

    cout << "printing post order traversal of badBST -->" << endl << "(";
    printPostOrder(badBST);
    cout << ")" << endl;

    cout << "printing post order traversal of badBST_left_linear -->" << endl << "(";
    printPostOrder(badBST_left_linear);
    cout << ")" << endl;

    cout << "printing post order traversal of current tree -->" << endl << "(";
    printPostOrder(root);
    cout << ")" << delim;

    Node* neg_tree = NULL;
    neg_tree = insert(neg_tree, -6);
    neg_tree = insert(neg_tree, -6);
    neg_tree = insert(neg_tree, -42);
    neg_tree = insert(neg_tree, -41);
    neg_tree = insert(neg_tree, -108);
    neg_tree = insert(neg_tree, 0);
    neg_tree = insert(neg_tree, 0);

    cout << "in order traversal of neg_tree --> " << endl << "(";
    printTree(neg_tree);
    cout << ")" << endl;

    cout << "post order traversal of neg_tree --> " << endl << "(";
    printPostOrder(neg_tree);
    cout << ")" << endl;

    int target_sum = -6;
    cout << "neg_tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = -12;
    cout << "neg_tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = -102;
    cout << "neg_tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = -162;
    cout << "neg_tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = -95;
    cout << "neg_tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = 42;
    cout << "singleNodeTree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(singleNodeTree, target_sum) << endl;

    target_sum = 0;
    cout << "singleNodeTree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(singleNodeTree, target_sum) << endl;

    target_sum = 0;
    cout << "emptyTree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(emptyTree, target_sum) << endl;

    target_sum = 3;
    cout << "current tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 2;
    cout << "current tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 10;
    cout << "current tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 3;
    cout << "current tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 5;
    cout << "current tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 0;
    cout << "badBST tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(badBST, target_sum) << endl;

    target_sum = 0;
    cout << "badBST_left_linear tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(badBST_left_linear, target_sum) << endl;


    target_sum = 20;
    cout << "badBST_left_linear tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(badBST_left_linear, target_sum) << endl;

    cout << delim;

    cout << "root-to-leaf paths in current tree --> " << endl;
    printPaths(root);
    cout << endl;

    cout << "root-to-leaf paths in singleNodeTree tree --> " << endl;
    printPaths(singleNodeTree);
    cout << endl;

    cout << "root-to-leaf paths in emptyTree tree --> " << endl;
    printPaths(emptyTree);
    cout << endl;

    cout << "root-to-leaf paths in badBST tree --> " << endl;
    printPaths(badBST);
    cout << endl;

    cout << "root-to-leaf paths in badBST_left_linear tree --> " << endl;
    printPaths(badBST_left_linear);
    cout << endl;

    cout << "root-to-leaf paths in neg_tree tree --> " << endl;
    printPaths(neg_tree);

    cout << delim;

    mirror(root);
    cout << "in-order traversal of current tree after mirror -->" << endl;
    printTree(root);
    cout << endl;
    cout << "post-order traversal of current tree after mirror -->" << endl;
    printPostOrder(root);
    cout << endl;
    mirror(root);
    cout << endl;

    mirror(neg_tree);
    cout << "in-order traversal of neg_tree tree after mirror -->" << endl;
    printTree(neg_tree);
    cout << endl;
    cout << "post-order traversal of neg_tree tree after mirror -->" << endl;
    printPostOrder(neg_tree);
    cout << endl;
    mirror(neg_tree);
    cout << endl;

    cout << delim;

    doubleTree(root);
    cout << "in-order traversal of current tree after doubleTree -->" << endl;
    printTree(root);
    cout << endl;
    cout << "post-order traversal of current tree after doubleTree -->" << endl;
    printPostOrder(root);
    cout << endl;

    doubleTree(neg_tree);
    cout << "in-order traversal of neg_tree tree after doubleTree -->" << endl;
    printTree(neg_tree);
    cout << endl;
    cout << "post-order traversal of neg_tree tree after doubleTree -->" << endl;
    printPostOrder(neg_tree);
    cout << endl;

    cout << delim;
    
    Node* copy_root = copyTree(root);
    cout << "in-order traversal of current tree and copy tree-->" << endl;
    printTree(root);
    cout << endl;
    printTree(copy_root);
    cout << endl;

    cout << "post-order traversal of current tree and copy tree -->" << endl;
    printPostOrder(root);
    cout << endl;
    printPostOrder(copy_root);
    cout << endl;

    cout << endl;

    Node* copy_neg_tree = copyTree(neg_tree);
    cout << "in-order traversal of neg_tree tree and copy neg_tree-->" << endl;
    printTree(neg_tree);
    cout << endl;
    printTree(copy_neg_tree);
    cout << endl;

    cout << "post-order traversal of neg_tree tree and copy neg_tree -->" << endl;
    printPostOrder(neg_tree);
    cout << endl;
    printPostOrder(copy_neg_tree);
    cout << endl;

    cout << delim;

    Node *copy_emptyTree = NULL;
    cout << "emptyTree mirror of emptyTree (expected 1)? " << sameTree(emptyTree, emptyTree) << endl;
    cout << "emptyTree mirror of copy_emptyTree (expected 1)? " << sameTree(emptyTree, copy_emptyTree) << endl;

    cout << "neg_tree mirror of copy_neg_tree (expected 1)? " << sameTree(neg_tree, copy_neg_tree) << endl;


    cout << "current tree mirror of neg_tree (expected 0)? " << sameTree(root, neg_tree) << endl;

    cout << "current tree mirror of copy_current_tree (expected 1)? " << sameTree(root, copy_root) << endl;

    cout << "current tree mirror of emptyTree (expected 0)? " << sameTree(root, emptyTree) << endl;

    cout << delim;

    int num_elements = 2;
    cout << "number of structurully unique b.s.t with " << num_elements <<
        " is (expected 2) " << countTrees(num_elements) << endl;

    num_elements = 3;
    cout << "number of structurully unique b.s.t with " << num_elements <<
        " is (expected 5) " << countTrees(num_elements) << endl;

    num_elements = 4;
    cout << "number of structurully unique b.s.t with " << num_elements <<
        " is (expected 14) " << countTrees(num_elements) << endl;
    cout << delim;

    int sz = 9;
    int io[] = {-4, 3, 12, 19, 6, 5, 18, 16, 12};
    int pre_o[] = {6, 12, -4, 3, 19, 5, 16, 18, 12};
    vector<int> new_tree_in_order(io, io + sz);
    vector<int> new_tree_pre_order(pre_o, pre_o + sz);

    Node* new_tree_root = get_BTree(new_tree_pre_order, 
            new_tree_in_order);

    cout << "post order of new tree expected --> \n(" << 
        "3 -4 19 12 18 12 16 5 6) got -->" << endl;
    printPostOrder(new_tree_root);
    cout << endl;

    sz = 5;
    int io1[] = {1, 2, 6, 5, 7};
    int pre_o1[] = {5, 2, 1, 6, 7};
    vector<int> tricky_btree_in_order(io1, io1 + sz);
    vector<int> tricky_btree_pre_order(pre_o1, pre_o1 + sz);

    Node* tricky_btree_root = get_BTree(tricky_btree_pre_order,
            tricky_btree_in_order);
    cout << "post order of tricky btree expected --> \n(" << 
        "1, 6, 2, 7, 5) got -->" << endl;
    printPostOrder(tricky_btree_root);
    cout << endl;

    int io2[] = {1, 2, 4, 5, 5};
    int pre_o2[] = {5, 2, 1, 4, 5};
    vector<int> tricky_btree_in_order2(io2, io2 + sz);
    vector<int> tricky_btree_pre_order2(pre_o2, pre_o2 + sz);
    Node* tricky_btree_root2 = get_BTree(tricky_btree_pre_order2,
            tricky_btree_in_order2);
    cout << "post order of tricky btree 2 expected --> \n(" << 
        "1, 4, 2, 5, 5) got -->" << endl;
    printPostOrder(tricky_btree_root2);
    cout << endl << delim;


    cout << "isBST_v1 tricky_btree_root (expected 0) --> " << 
        isBST_v1(tricky_btree_root) << endl;

    cout << "isBST_v1 tricky_btree_root2 (expected 0) --> " << 
        isBST_v1(tricky_btree_root2) << endl;

    cout << "isBST_v1 root (expected 1) --> " << 
        isBST_v1(root) << endl;

    cout << "isBST_v1 new_tree_root (expected 0) --> " << 
        isBST_v1(new_tree_root) << endl;

    cout << "isBST_v1 emptyTree (expected 1) --> " << 
        isBST_v1(emptyTree) << endl;

    cout << "isBST_v1 badBST (expected 1) --> " << 
        isBST_v1(badBST) << endl;

    cout << "isBST_v1 badBST_left_linear (expected 1) --> " << 
        isBST_v1(badBST_left_linear) << endl;

    cout << delim;

    cout << "isBST_v2 tricky_btree_root (expected 0) --> " << 
        isBST_v2(tricky_btree_root) << endl;

    cout << "isBST_v2 tricky_btree_root2 (expected 0) --> " << 
        isBST_v2(tricky_btree_root2) << endl;

    cout << "isBST_v2 root (expected 1) --> " << 
        isBST_v2(root) << endl;

    cout << "isBST_v2 new_tree_root (expected 0) --> " << 
        isBST_v2(new_tree_root) << endl;

    cout << "isBST_v2 emptyTree (expected 1) --> " << 
        isBST_v2(emptyTree) << endl;

    cout << "isBST_v2 badBST (expected 1) --> " << 
        isBST_v2(badBST) << endl;

    cout << "isBST_v2 badBST_left_linear (expected 1) --> " << 
        isBST_v2(badBST_left_linear) << endl;

    cout << delim;

    cout << "max path sum for tricky_btree_root --> expected(20): " <<
        maxPathSum(tricky_btree_root) << endl;
    cout << "max path sum for tricky_btree_root2 --> expected(16): " <<
        maxPathSum(tricky_btree_root2) << endl;

    cout << "max path sum for current tree --> expected(19): " <<
        maxPathSum(root) << endl;

    cout << "max path sum for neg_tree --> expected(0): " <<
        maxPathSum(neg_tree) << endl;

    sz = 8;
    int io3[] = {20, 2, 1, 10, 10, 3, -25, 4};
    int pre_o3[] = {10, 2, 20, 1, 10, -25, 3, 4};
    vector<int> tricky_btree_in_order3(io3, io3 + sz);
    vector<int> tricky_btree_pre_order3(pre_o3, pre_o3 + sz);
    Node* tricky_btree_root3 = get_BTree(tricky_btree_pre_order3,
            tricky_btree_in_order3);
    cout << "post order of tricky btree 3 expected --> \n(" << 
        "20 1 2 3 4 -25 10 10) got -->" << endl;
    printPostOrder(tricky_btree_root3);
    cout << endl;

    cout << "max path sum for tricky_btree_root3 --> expected(42): " <<
        maxPathSum(tricky_btree_root3) << endl;

    cout << delim;


}
