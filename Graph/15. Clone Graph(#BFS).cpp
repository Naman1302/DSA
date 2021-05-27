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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;//if no node given
        unordered_map<Node*,Node*> m; //map to store adressess of original as key and copy as value
        queue<Node*> q;//we do bfs here as dfs takes much more time
        q.push(node);
        
        Node* kode=new Node();//Our Clone Node
        kode->val=node->val;
        
        m[node]=kode;
        while(!q.empty()){
            Node *u=q.front();
            q.pop();
            vector<Node*> v=u->neighbors;
            int n=v.size();
            for(int i=0;i<n;i++){//for every adjacent element of given node as we do in all bfs
                if(m[v[i]]==NULL){//If node has not been created,we'll create  one
                    Node* temp=new Node();
                    temp->val=v[i]->val;
                    m[v[i]]=temp;
                    q.push(v[i]);
                }
                m[u]->neighbors.push_back(m[v[i]]);//finally pushing that clone node in its right place i.e. m[u] gives adress of clone of u node of which neighbours vector we push_back it's clone
            }
        }
        return m[node];
    }
};
