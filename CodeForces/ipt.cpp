#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Company
{
    string name;
    int duration; // min
    int rounds;
    int panels;
};

struct Slot
{
    string company;
    int round;
    int start;
    int end;
    int panel;
};

string timeToStr(int minutes)
{
    int hour = 9 + minutes / 60;
    int minute = minutes % 60;
    string period = (hour >= 12) ? "PM" : "AM";
    if (hour > 12)
        hour -= 12;
    stringstream ss;
    ss << hour << ":" << setw(2) << setfill('0') << minute << " " << period;
    return ss.str();
}

int main()
{
    int n; // students
    cin >> n;
    vector<string> students(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> students[i];
    }

    int m; // companies
    cin >> m;
    vector<Company> companies(m);
    map<string, int> companyIndex;
    for (int i = 0; i < m; ++i)
    {
        cin >> companies[i].name >> companies[i].duration >> companies[i].rounds >> companies[i].panels;
        companyIndex[companies[i].name] = i;
    }

    vector<vector<string>> shortlist(n);
    for (int i = 0; i < n; ++i)
    {
        int cnt;
        cin >> cnt;
        shortlist[i].resize(cnt);
        for (int j = 0; j < cnt; ++j)
        {
            cin >> shortlist[i][j];
        }
    }

    int t1, t2;
    cin >> t1 >> t2;
    int totalMinutes = (t2 - t1) * 60;

    // Panel availability: company -> panel -> next available time
    map<string, vector<int>> panelAvailability;
    for (const auto &comp : companies)
    {
        panelAvailability[comp.name] = vector<int>(comp.panels, 0); // all start at 0
    }

    map<string, vector<Slot>> schedule;
    bool success = true;

    for (int i = 0; i < n && success; ++i)
    {
        string student = students[i];
        int studentAvailable = 0; // student available time
        for (const string &cname : shortlist[i])
        {
            Company comp = companies[companyIndex[cname]];
            for (int r = 1; r <= comp.rounds; ++r)
            {
                int bestTime = 1e9, chosenPanel = -1;
                for (int p = 0; p < comp.panels; ++p)
                {
                    if (panelAvailability[cname][p] < bestTime)
                    {
                        bestTime = panelAvailability[cname][p];
                        chosenPanel = p;
                    }
                }

                int start = max(bestTime, studentAvailable); // no overlap
                int end = start + comp.duration;

                if (end > totalMinutes)
                {
                    success = false;
                    break;
                }

                schedule[student].push_back({cname, r, start, end, chosenPanel + 1});
                panelAvailability[cname][chosenPanel] = end;
                studentAvailable = end; // Update student's time
            }
            if (!success)
                break;
        }
    }

    // Output
    for (const string &s : students)
    {
        cout << s << "\n";
        cout << "Company\tRound\tStart\tEnd\tPanel\n";
        for (const Slot &slot : schedule[s])
        {
            cout << slot.company << "\t" << slot.round << "\t"
                 << timeToStr(slot.start) << "\t" << timeToStr(slot.end) << "\t"
                 << slot.panel << "\n";
        }
        if (!success)
        {
            cout << "FURTHER SCHEDULING NOT POSSIBLE\n";
            return 0;
        }
    }

    return 0;
}
