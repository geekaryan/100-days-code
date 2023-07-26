// 1870. Minimum Speed to Arrive on Time
// You are given a floating-point number hour, representing the amount of time you have to reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.

// Each train can only depart at an integer hour, so you may need to wait in between each train ride.

// For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.
// Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.

// Tests are generated such that the answer will not exceed 107 and hour will have at most two digits after the decimal point.

class Solution
{
public:
    bool isChecked(vector<int> &dist, int speed, double hour)
    {
        double ans = 0;
        for (int i = 0; i < dist.size(); i++)
        {
            double d = dist[i] * 1.0 / speed;
            if (i != dist.size() - 1)
            {
                ans = ans + ceil(d);
            }
            else
            {
                ans += d;
            }
            if (ans > hour)
            {
                return false;
            }
        }
        if (ans <= hour)
        {
            return true;
        }
        return false;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {

        int l = 1;
        int r = 1e7 + 2;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isChecked(dist, mid, hour))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (l > 1e7 + 2)
        {
            return -1;
        }

        return l;
    }
};