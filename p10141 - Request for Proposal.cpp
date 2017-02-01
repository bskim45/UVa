#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

#define FLUSH() while(getchar() != '\n');

using namespace std;

class RFP {
public:
    RFP(const string& name, const double price, const int req)
            : name(name), price(price), req(req) { }

    string name;
    double price;
    int req;
};

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);

    int req_num = 0;
    int proposal_num = 0;
    double price = 0;
    int req = 0;
    char buffer[80];
    vector<RFP> rfps;

    for(int case_num = 1; ; ++case_num) {
        scanf("%d %d", &req_num, &proposal_num);

        if (req_num == 0) {
            break;
        }

        rfps.clear();

        FLUSH()
        for (int i = 0; i < req_num; ++i) {
            gets(buffer);
        }

        for (int i = 0; i < proposal_num; ++i) {
            // name
            gets(buffer);

            // price reqs
            scanf("%lf %d", &price, &req);
            RFP rfp(buffer, price, req);
            rfps.push_back(rfp);

            FLUSH()
            for (int j = 0; j < req; ++j) {
                gets(buffer);
            }
        }

        sort(rfps.begin(), rfps.end(), [](const RFP& lhs, const RFP& rhs)
        {
            if(lhs.req == rhs.req) {
                return lhs.price < rhs.price;
            } else {
                return lhs.req > rhs.req;
            }
        });

        if(case_num != 1) {
            printf("\n");
        }
        printf("RFP #%d\n", case_num);
        printf("%s\n", rfps.front().name.c_str());
    }

    return 0;
}
