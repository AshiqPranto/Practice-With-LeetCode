class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        pair<int,int>ev1s,ev1e,ev2s,ev2e;
        ev1s.first = stoi(event1[0].substr(0,2));
        ev1s.second = stoi(event1[0].substr(3,2));
        
        ev1e.first = stoi(event1[1].substr(0,2));
        ev1e.second = stoi(event1[1].substr(3,2));
        
        
        ev2s.first = stoi(event2[0].substr(0,2));
        ev2s.second = stoi(event2[0].substr(3,2));
        
        ev2e.first = stoi(event2[1].substr(0,2));
        ev2e.second = stoi(event2[1].substr(3,2));
        
        
        if(ev1s.first>ev2s.first)
        {
            swap(ev1s,ev2s);
            swap(ev1e,ev2e);
        }
        else if(ev1s.first == ev2s.first)
        {
            if(ev1s.second > ev2s.second)
            {        
                swap(ev1s,ev2s);
                swap(ev1e,ev2e);
            }
        }
        
        if(ev1e.first < ev2s.first)
        {
            return false;
        }
        else if(ev1e.first == ev2s.first)
        {
            if(ev1e.second < ev2s.second)
            {
                return false;
            }
        }
        return true;
        
    }
};