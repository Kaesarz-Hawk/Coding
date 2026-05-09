class solution {
public:
int compute( int n , int x , vector<int>&a , vector<int>&b ) {
    int count = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( a[i] >= x )
        {
            count += b[i];
            
        }
    }
    return count;
    return count;
} 
};