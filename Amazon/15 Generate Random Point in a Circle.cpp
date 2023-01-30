class Solution {
public:
    double rad;
    double x;
    double y;
    double pi = 3.14159265359;
    Solution(double radius, double x_center, double y_center) {
        rad = radius;
        x = x_center;
        y = y_center;
    }
    double getrandom() {
        return rand()/(double)RAND_MAX;
    }
    vector<double> randPoint() {
       
        double theta = getrandom()*2*pi;
        double len = sqrt(getrandom())*rad;
        double newx = x + len*cos(theta);
        double newy = y + len*sin(theta);
        return {newx,newy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
