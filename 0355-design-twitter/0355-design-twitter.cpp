// class Twitter {
//     private:
//     //pairs:[user,tweet]
//     vector<pair<int,int>>posts;
//    //hash map:{user->people they follow}
//    unordered_map<int,unordered_set<int>>followMap; 
// public:
//     Twitter() {
        
//     }
    
//     void postTweet(int userId, int tweetId) {
//         posts.push_back({userId,tweetId});
//     }
    
//     vector<int> getNewsFeed(int userId) {
//         int cnt=10;//ten tweets we need
//         vector<int>result;

//         for(int i=posts.size()-1;i>=0;i--){
//             if(cnt==0){
//                 break;
//             }

//             int followingId=posts[i].first;
//             int tweetId=posts[i].second;
//             unordered_set<int>following=followMap[userId];
//             //add to result if they're following them or it's a tweetfrom themself

//             if(following.find(followingId)!=following.end()||followingId==userId){
//                 result.push_back(tweetId);
//                 cnt--;
//             }
//         }
//             return result;

//       }
    
    
//     void follow(int followerId, int followeeId) {
//         followMap[followerId].insert(followeeId);
//     }
    
//     void unfollow(int followerId, int followeeId) {
//           followMap[followerId].erase(followeeId);
//     }
// };

// class Twitter {
// private:    
//    unordered_map<int, set<int>> fo;
//    unordered_map<int, vector<pair<int, int>>> t;
//    long long time; 

// public:
// /** Initialize your data structure here. */
// Twitter() {
//     time = 0;
// }

// /** Compose a new tweet. */
// void postTweet(int userId, int tweetId) {
//     t[userId].push_back({time++, tweetId});
// }

// /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
// vector<int> getNewsFeed(int userId) {
//     priority_queue<pair<int, int>> maxHeap; 
//     for (auto it=t[userId].begin();it!=t[userId].end();++it)
//         maxHeap.push(*it);
//     for (auto it1=fo[userId].begin();it1!=fo[userId].end();++it1){
//         int usr = *it1; // get target user
//         for (auto it2=t[usr].begin();it2!=t[usr].end();++it2)
//             maxHeap.push(*it2);
//     }   
//     vector<int> res;
//     while(maxHeap.size()>0) {
//         res.push_back(maxHeap.top().second);
//         if (res.size()==10) break;
//         maxHeap.pop();
//     }
//     return res;
// }

// /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
// void follow(int followerId, int followeeId) {
//     if (followerId != followeeId)
//         fo[followerId].insert(followeeId);
// }

// /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
// void unfollow(int followerId, int followeeId) {
//     fo[followerId].erase(followeeId);
// }
// };

class Twitter {
public:
   int freq =0;

   unordered_map<int,vector<pair<int,int>>>users;
   unordered_map<int,set<int>>followers;


    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
       users[userId].push_back({freq,tweetId});
       freq++;
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int>ans;
        
        auto temp=users[userId];

        auto st=followers[userId];

        for(auto &x:st){
            auto temp2=users[x];
            for(auto &y:temp2){
                temp.push_back(y);
            }
        }
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        
        if(temp.size()>10){
            for(int i=0;i<10;i++){
                ans.push_back(temp[i].second);
            }
        }
        else{
            for(int i=0;i<temp.size();i++){
               ans.push_back(temp[i].second);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
       auto temp=followers[followerId];

       if(temp.find(followeeId)!=temp.end()){
        followers[followerId].erase(followeeId);
       }

    }
};


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
