//

//O(N) + O(N) #DFS

  class Solution {
  public:
      std::vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
          std::vector<int> res;

          distanceK(root, target, K, res);

          return res;
      }

  private:
      int distanceK(TreeNode* node, TreeNode* target, int K, std::vector<int>& res) {
          if (node == nullptr) {
              return 0;
          }
          if (node == target) {  // found the target for the current subtree
              traverseSubtree(node, K, res);
              return 1;
          }
          int distLeft = distanceK(node->left, target, K, res); // distance to target in the left subtree

          if (distLeft != 0) {
              if (distLeft == K) {
                  res.push_back(node->val);
              } else if (distLeft < K) {
                  traverseSubtree(node->right, K - distLeft - 1, res); // visit the right subtree looking for nodes at a given distance
              }
              return distLeft + 1; //  return distance to target + 1
          }   
          int distRight = distanceK(node->right, target, K, res); // distance to target in the right subtree

          if (distRight != 0) {
              if (distRight == K) {
                  res.push_back(node->val);
              } else if (distRight < K) {
                  traverseSubtree(node->left, K - distRight - 1, res);  // visit the left subtree looking for nodes at a given distance
              }
              return distRight + 1; //  return distance to target + 1
          }
          return 0; // if reached this place, then there is no target in the current subtree
      }

      void traverseSubtree(TreeNode* node, int K, std::vector<int>& res) {
          if (node == nullptr) {
              return;
          }
          if (K == 0) { // found a node at a given distance
              res.push_back(node->val);
              return;
          }
      traverseSubtree(node->left,  K - 1, res);  // go down until we find a node at a distance of K 
          traverseSubtree(node->right, K - 1, res);  // (if the depth of the subtree allows us to do this)
      }
  };

//Iterative #BFS

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { /*First BFS to get a track of parent nodes*/
            TreeNode* current = queue.front(); queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == K) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }

