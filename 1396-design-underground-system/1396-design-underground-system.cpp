class UndergroundSystem {
public:
    map<int,pair<string,int>> m;
    map<pair<string,string>,int> p;
    map<pair<string,string>,int> c;
    UndergroundSystem() {
        m.clear();
        p.clear();
        c.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        p[{m[id].first,stationName}]+=t-m[id].second;
        c[{m[id].first,stationName}]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans=(double)p[{startStation,endStation}]/(double)c[{startStation,endStation}];
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */