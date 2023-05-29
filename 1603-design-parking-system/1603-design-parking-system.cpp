class ParkingSystem {
public:
    vector<int> v;
    ParkingSystem(int big, int medium, int small) {
        v.resize(3,0);
        v[0]=big;
        v[1]=medium;
        v[2]=small;
    }
    
    bool addCar(int carType) {
        carType--;
        return v[carType]?v[carType]--:0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */