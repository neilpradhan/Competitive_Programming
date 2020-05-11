/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// #include <queue>
#include <bits/stdc++.h>
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node){
            return NULL;
        }
        
        unordered_map<Node*,Node*> mp;
        
        
        Node* cloned_root = new Node(node->val);
        
        mp[node] = cloned_root; // done pairing old node and new node
        
        queue<pair<Node*, Node*>> q;
        
        q.push(make_pair(node,cloned_root));
        
        // after putting the new root node in map and queue
        while (!q.empty()){
            Node* curr_parent = q.front().first;
            Node* curr_new_parent  = q.front().second;
            q.pop();

            // for every child 
            for (int i =0;i<curr_parent->neighbors.size();i++){
                
                auto it  = mp.find(curr_parent->neighbors[i]);
                // check if that child  already in map
                Node* og_child = curr_parent->neighbors[i];
                if (it == mp.end()){
                    // if child  doesnot exist make the new child
                    Node* new_child = new Node (og_child->val);
                    mp[curr_parent->neighbors[i]] = new_child; // associate with parent
                    q.push(make_pair(curr_parent->neighbors[i],new_child));
                    curr_new_parent->neighbors.push_back(new_child);
                    
                    
                }else{
                    // parent already exist in map
                    // only make the required association parent child
                    curr_new_parent->neighbors.push_back(it->second);
                }
                
            }// for loop ends
            
        }// while loop
        
        return cloned_root;
         
    }
};
