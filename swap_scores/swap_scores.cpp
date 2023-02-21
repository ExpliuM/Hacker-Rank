/*
 * Link: 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <functional>

class Contest {
    std::vector<int> scores;
    Contest& operator=(Contest);
public:
    Contest(std::vector<int> v) : scores{v} {
        std::cout << "Before swapping the scores: ";
        copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    void print_scores() {
        std::cout << "After swapping the scores: ";
        copy(scores.begin(), scores.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    void swap(Contest& other){ 
        this->scores.swap(other.scores);
    }
};

/*
 * Complete the function signature.
 */
void swap_scores(std::vector<int> first, std::vector<int> second) {
    /*
     * 1. Instantiate the object first_contest with the scores provided by the array first.
     */
    Contest first_contest(first);
    
    /*
     * 2. Instantiate the object second_contest with the scores provided by the array second.
     */
    Contest second_contest(second);
    
    
    /*
     * 3. Swap the scores of the both the contest objects.
     */
    first_contest.swap(second_contest);


    /*
     * 4. Invoke the member function print_scores for the object first_contest.
     */
    first_contest.print_scores();
    
    /*
     * 5. Invoke the member function print_scores for the object second_contest.
     */
    second_contest.print_scores();
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> first(n);
    for (int i = 0; i < n; i++) {
        std::cin >> first[i];
    }

    int m;
    std::cin >> m;

    std::vector<int> second(m);
    for (int i = 0; i < m; i++) {
        std::cin >> second[i];
    }

    swap_scores(std::cref(first), std::cref(second));

    return 0;
}