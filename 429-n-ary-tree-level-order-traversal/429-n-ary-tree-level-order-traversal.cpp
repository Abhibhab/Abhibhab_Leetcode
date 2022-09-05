/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector < vector < int >> levelOrder(Node * root) {
        if(root==NULL){
             vector < vector < int >>vec;
            return vec;
            
        }
   vector < vector < int >> vec;
   queue < Node * > que;
   que.push(root);
   while (!que.empty()) {
     int s = que.size();
     vector < int > inter;
     for (int i = 0; i < s; i++) {
       Node * hi = que.front();
       que.pop();

       for (int i = 0; i < hi -> children.size(); i++) {
           if(hi->children[i]!=NULL){
         que.push(hi -> children[i]);
           }
       }
       inter.push_back(hi -> val);
     }
     vec.push_back(inter);

   }
   return vec;

 }
};