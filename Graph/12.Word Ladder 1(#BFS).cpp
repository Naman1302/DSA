int wordLadderLength(string start,string target, vector<string>& list) {
        // Code here
        if(start==target) //No need to go anywhere
            return 0;
        unordered_set<string> s;//to handle mutiple occourences and to find words easily
        bool isPresent=false;//maybe the target is not in list then!!
        for(int i=0;i<list.size();i++){
            if(list[i]==target)
                isPresent=true;
            s.insert(list[i]);
        }
        
        if(!isPresent)
            return 0;
            
        queue<string> q;//BFS
        q.push(start);
        int depth=1;//initially we have a word so from it we have to go to end word => min_depth=1
        while(!q.empty()){
            int size=q.size();//For every element we need to traverse its adjacency
            while(size--){
                string temp=q.front();
                q.pop();
                for(int i=0;i<temp.size();i++){//for our frot word we take it's each letter and try all alphabetical possiblities
                    char let=temp[i];
                    for(char c='a';c<='z';c++){
                        if(c==let) continue;//we do nothin if we hit the same letter as in our front word cause that will just lead in wastage of time
                        else{
                            temp[i]=c;//transformation
                            if(s.find(temp)!=s.end()){//if the created word is in list
                                if(temp==target){
                                    return depth+1;//including the target word
                                }
                                q.push(temp);
                                s.erase(temp);//erasing occourence of this word from set cause we don't wwant to repeat in loop
                            }
                            temp[i]=let;//changing back
                        }
                    }
                }
            }
            depth++;//one word has completed so depth+1
        }
        return 0;
    }
