// bool compare(vector<int>& v1, vector<int>& v2) {
//     return v1[0] < v2[0];
// }

// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         /* Sort the meetings based on start_time */
//         sort(meetings.begin(), meetings.end(), compare);
        
//         /* Create a priority queue for engaged rooms. Each node of PQ will store {current_meeting_ending_time, room_number} */
//         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged;
        
//         /* Create a priority queue for non-engaged rooms. Each node of PQ will store {room_number} */
//         priority_queue<int, vector<int>, greater<int>> unused;
        
//         /* Frequency map to store the frequency of meetings in each room */
//         unordered_map<int, int> freq;
        
//         /* Currently all the rooms are mepty */
//         for(int i = 0; i < n; i++) {
//             unused.push(i);
//         }
        
//         for(auto x:meetings) {
//             int s = x[0], e = x[1];
            
//             /* Move the meeting rooms in engaged, with ending_time <= s, to unused */ 
//             while(engaged.size() > 0 && engaged.top().first <= s) {
//                 int room = engaged.top().second;
//                 engaged.pop();
                
//                 unused.push(room);
//             }
            
//             /* If there are multiple empty rooms, choose the one with lower room_number */
//             if(unused.size() > 0) 
//             {
//                 int room = unused.top();
//                 unused.pop();
                
//                 freq[abs(room)] += 1;
                
//                 /* Mark the room as engaged */
//                 engaged.push({e, room});
//             }
//             /* If there are no empty rooms, wait for the engaged room with nearest ending time to empty */
//             else 
//             {
//                 pair<long long, int> topmost = engaged.top();
//                 engaged.pop();
            
//                 freq[abs(topmost.second)] += 1;
                
//                 /* Since duration has to be the same, the newEnd will be sum(end_time_of_the_prev_meeting, duration) */ 
//                 long long newEnd = topmost.first;
//                 newEnd += (e - s);
                
//                 /* Mark the room as engaged */
//                 engaged.push({newEnd, topmost.second});
//             }
//         }
        
//         /* Find the lowest room_number with maximum frequency */
//         int maxi = 0;
//         for(int i = 1; i < n; i++) {
//             cout<<i<<" = "<<freq[i]<<endl;
//             if(freq[i] > freq[maxi])
//                 maxi = i;
//         }
//         return maxi;
//     }
// };



class Solution {
public:
    
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>free_room;
        sort(meetings.begin(),meetings.end());
        int sz = meetings.size();
        // cout<<sz<<endl;
        vector<pair<long long,int>>rooms;
        for(int i = 0;i<sz;i++)
        {
            rooms.push_back({meetings[i][0],(meetings[i][1]-meetings[i][0])});
        }
        sort(rooms.begin(),rooms.end());
        for(int i = 0;i<n;i++) free_room.push({0,i});
        int ans[105] = {0};
        memset(ans,0,sizeof(ans));
        int ans1 = 0;
        int meet = 0;
        for(int i = 0;i<sz;i++)
        {
            // pair<long long,int> free = calculate_room(rooms[i].first);
            pair<long long,int> current = rooms[i];
            while(free_room.top().first < current.first)
            {
                long long a = free_room.top().first;
                int b = free_room.top().second;
                free_room.pop();
                free_room.push({current.first,b});
            }
            pair<long long,int>free = free_room.top();
            free_room.pop();
            int delay = 0;
            if(free.first>current.first) delay = free.first-current.first;
            // if(free.first>current.first) delay = free.first-current.first;
            ans[free.second]++;
            // if(ans[free.second]>meet) ans1 = free.second,meet = ans[free.second];
            // else if(ans[free.second] == meet) ans1 = min(ans1,free.second);
            // cout<<free.second<<endl;
            free_room.push({(free.first+current.second),free.second});
        }
        int maximum = 0;
        int index = 0;
        for(int i = 0;i<n;i++) 
        {
            // cout<<i<<" = "<<ans[i]<<endl;
            if(ans[i]>maximum) 
            {
                index = i;
                maximum = ans[i];
            }
            
        }
        return index;
        
    }
};

