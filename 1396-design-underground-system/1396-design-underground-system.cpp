class UndergroundSystem {
public:
    
    map<int,pair<string,int>>checkinvalue;
    map<pair<string,string>,pair<int,int>>ans;
    
    UndergroundSystem() {
        checkinvalue.clear();
        ans.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkinvalue[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int temp = t - checkinvalue[id].second;
        pair<string,string> key = {checkinvalue[id].first,stationName};
        ans[key] = {ans[key].first+temp,ans[key].second+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return ans[{startStation,endStation}].first/(ans[{startStation,endStation}].second+0.0);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */