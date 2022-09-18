/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& in, vector<int>& pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS; //left inorder start
	int lInE = rootIndex - 1;//left inorder end
	int lPreS = preS + 1;//left preorder start
	int lPreE = lInE - lInS + lPreS;//left preorder end
	int rPreS = lPreE + 1;//right preorder start
	int rPreE = preE;//right preorder end
	int rInS = rootIndex + 1;//right inorder start
	int rInE = inE;//right inorder end
	TreeNode*  root = new TreeNode(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}
 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(inorder,preorder,0,inorder.size()-1,0,preorder.size()-1);
        
    }
};