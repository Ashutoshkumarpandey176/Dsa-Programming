class Solution {
public:
bool possiblehai(vector<int>&time,long long givenTime,int totalTrips)
{
    long long actualtrip=0;
    for(int &t:time)
    {
        actualtrip+=givenTime/t;
    }
    return actualtrip>=totalTrips;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();

long long l=1;
long long r=(long long) *min_element(begin(time),end(time))*totalTrips;

while(l<r)
{
    long long mid_time=l+(r-l)/2;
    if(possiblehai(time,mid_time,totalTrips))
    {
        r=mid_time;
    }
    else
    {
        l=mid_time+1;
    }
}
return l;
    }
};