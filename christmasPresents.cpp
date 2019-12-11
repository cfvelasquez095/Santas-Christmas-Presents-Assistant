#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

struct kid
{
    int id;
    int actions;
    bool nice;
};

bool compareById(const kid &a, const kid &b)
{
    return a.id < b.id;
}

int find_index_sorted(const std::vector<kid>& k_list, int ident)
{
    struct lower_ident
    {
        constexpr bool operator()(const kid& l, int r) const {
            return l.id < r;
        }

        constexpr bool operator()(int l, const kid& r) const {
            return l < r.id;
        }
    };
    constexpr auto pred = lower_ident();
    auto it = std::lower_bound(k_list.begin(), k_list.end(), ident, pred);
    if (it == k_list.end() or pred(ident, *it))
        return -1;
    return it - k_list.begin();
}

void query_results(std::vector<struct kid> nice_list, std::vector<struct kid> naughty_list, std::vector<int> query_list, int limit)
{
    std::sort(nice_list.begin(), nice_list.end(), compareById);
    std::sort(naughty_list.begin(), naughty_list.end(), compareById);

    struct kid current_kid;
    int nice_pos, naughty_pos;

    for (int i = 0; i < static_cast<int>(query_list.size()); i++)
    {
        nice_pos = find_index_sorted(nice_list, query_list.at(i));
        naughty_pos = find_index_sorted(naughty_list, query_list.at(i));
        
        if ((nice_list.at(nice_pos).actions - naughty_list.at(naughty_pos).actions) >= limit)
        {
            std::cout << "1 ";
        } else
        {
            std:: cout << "0 ";
        }
    }
    
}


int main(int argc, char const *argv[])
{
    int total_kids, actions_limit, kid_id, kid_actions, query;
    std::vector<struct kid> nice_list, naughty_list;
    std::vector<int> query_list;
    struct kid kid;
    clock_t t;
    
    std::cin >> total_kids;
    std::cin >> actions_limit;
    std::cout << "Start nice list" << std::endl;
    // We will start filling the Nice Actions list.
    for (int i = 0; i < total_kids; i++)
    {
        std::cin >> kid_id >> kid_actions;

        kid.id = kid_id;
        kid.actions = kid_actions;
        kid.nice = false;

        nice_list.push_back(kid);
    }
    std::cout << "Start naughty list" << std::endl;
    // We will start filling the Naughty Actions list.
    for (int i = 0; i < total_kids; i++)
    {
        std::cin >> kid_id >> kid_actions;

        kid.id = kid_id;
        kid.actions = kid_actions;
        kid.nice = false;

        naughty_list.push_back(kid);
    }
    // Santa will ask how many kids for the query.
    std::cin >> query;
    // Santa will ask for the id's of the kids he want to gift based on the previous query.
    do
    {
        int input;
        if (std::cin >> input)
        {
            query_list.push_back(input);
        }
    } while (std::cin && std::cin.peek() != '\n');

    t = clock();
    query_results(nice_list, naughty_list, query_list, actions_limit);
    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nProgram took %f seconds to execute \n", time_taken);

    return 0;
}
