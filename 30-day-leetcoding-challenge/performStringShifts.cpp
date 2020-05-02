class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
    int sum = 0;
    for (int i = 0; i < shift.size(); i++)
    {
        int multiplier = 0;
        int amount = shift[i][1];
        if (shift[i][0] == 0)
            multiplier = 1;
        else
            multiplier = -1;

        sum += (multiplier * amount);
    }

    int overlaps = sum / (int)s.size();
    sum -= overlaps * s.size();

    if (sum < 0)
    {
        sum = s.size() + sum;
    }
    if (sum != 0)
    {
        rotate(s.begin(), s.begin() + sum, s.end());
    }
    return s;
}
};