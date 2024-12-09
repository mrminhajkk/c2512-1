#define DSUM(...)  findSum(__VA_ARGS__)

int main()
{
    cout << DSUM(2,3) << endl;
    cout << DSUM(2,3,5) << endl;
    cout << DSUM(2,3,5,6) << endl;
}