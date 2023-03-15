/**
 * @file fairy-chess.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/fairy-chess/problem?isFullScreen=true
 * @version 0.1
 * @date 2023-03-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <utility>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct Position
{
    int x;
    int y;

    Position(){};
    Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    };

    inline int operator<(const Position &p) const
    {
        return this->x < p.x || this->y < p.y;
    }
};

set<Position> leapPossiblePositions(Position &position, int s, vector<vector<char>> &board)
{
    set<Position> possiblePositions;

    int leapY = position.y;
    int leapX = position.x;

    int yBoundary = board.size();
    int xBoundary = board[0].size();

    for (int newY = max(0, leapY - s); newY <= min(leapY + s, yBoundary - 1); ++newY)
    {
        for (int newX = max(0, leapX - s); newX <= min(leapX + s, xBoundary - 1); ++newX)
        {
            int distance = abs(leapX - newX) + abs(leapY - newY);
            if (distance <= s && board[newY][newX] != 'P')
            {
                Position newPosition = Position(newX, newY);
                possiblePositions.insert(newPosition);
            }
        }
    }

    return possiblePositions;
}

vector<vector<set<Position>>> calcPossiblePositionsBoard(int s, vector<vector<char>> &board)
{
    int yLength = board.size();
    vector<vector<set<Position>>> possiblePositionsBoard(yLength);
    for (int yInd = 0; yInd < yLength; yInd++)
    {
        int xLength = board[yInd].size();
        possiblePositionsBoard[yInd] = vector<set<Position>>(xLength);
        for (int xInd = 0; xInd < xLength; xInd++)
        {
            Position p(xInd, yInd);
            possiblePositionsBoard[yInd][xInd] = leapPossiblePositions(p, s, board);
        }
    }
    return possiblePositionsBoard;
}

Position getLeapPosition(vector<vector<char>> board)
{
    int yLength = board.size();
    for (int yInd = 0; yInd < yLength; yInd++)
    {
        int xLength = board[yInd].size();
        for (int xInd = 0; xInd < xLength; xInd++)
        {
            if (board[yInd][xInd] == 'L')
            {
                return Position(xInd, yInd);
            }
        }
    }

    return Position();
}

void auxFairyChess(Position &position, int m, vector<vector<char>> &board, vector<vector<set<Position>>> &possiblePositionsBoard, vector<vector<int>> **waysBoard1, vector<vector<int>> **waysBoard2)
{
    if (m == 0)
    {
        return;
    }

    set<Position> possiblePositions = possiblePositionsBoard[position.y][position.x];
    if (m == 1)
    {
        for (Position newPosition : possiblePositions)
        {
            ++(**waysBoard1)[newPosition.y][newPosition.x];
        }
        return;
    }

    auxFairyChess(position, m - 1, board, possiblePositionsBoard, waysBoard1, waysBoard2);

    vector<Position> waysToUpdate;

    int yLength = (**waysBoard1).size();
    for (int yInd = 0; yInd < yLength; yInd++)
    {
        int xLength = (**waysBoard1)[yInd].size();
        for (int xInd = 0; xInd < xLength; xInd++)
        {
            if ((**waysBoard1)[yInd][xInd] > 0)
            {
                (**waysBoard2)[yInd][xInd] = 0;
                waysToUpdate.push_back(Position(xInd, yInd));
            }
        }
    }

    for (Position wayToUpdate : waysToUpdate)
    {
        set<Position> possiblePositions = possiblePositionsBoard[wayToUpdate.y][wayToUpdate.x];
        for (Position newPosition : possiblePositions)
        {
            (**waysBoard2)[newPosition.y][newPosition.x] += (**waysBoard1)[wayToUpdate.y][wayToUpdate.x];
        }
    }

    swap(*waysBoard1, *waysBoard2);
}

int calcSum(vector<vector<int>> &waysBoard)
{
    int sum = 0;
    for (vector<int> line : waysBoard)
    {
        for (int ways : line)
        {
            sum += ways;
        }
    }
    return sum;
}

int fairyChess(int m, int s, vector<vector<char>> board)
{
    Position position = getLeapPosition(board);
    vector<vector<set<Position>>> PossiblePositionsBoard = calcPossiblePositionsBoard(s, board);
    vector<vector<int>> waysBoard1(board.size(), vector<int>(board[0].size()));
    vector<vector<int>> waysBoard2(board.size(), vector<int>(board[0].size()));

    vector<vector<int>> *waysBoard1Ptr = &waysBoard1;
    vector<vector<int>> *waysBoard2Ptr = &waysBoard2;

    auxFairyChess(position, m, board, PossiblePositionsBoard, &waysBoard1Ptr, &waysBoard2Ptr);

    return calcSum(*waysBoard1Ptr);
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string nms_temp;
        getline(cin, nms_temp);

        vector<string> nms = split_string(nms_temp);

        int n = stoi(nms[0]);

        int m = stoi(nms[1]);

        int s = stoi(nms[2]);

        vector<vector<char>> board(n);

        for (int board_itr = 0; board_itr < n; board_itr++)
        {
            string boardLine;
            getline(cin, boardLine);

            std::vector<char> charLine(boardLine.begin(), boardLine.end());
            board[board_itr] = charLine;
        }

        int result = fairyChess(m, s, board);

        cout << result << "\n";
        // fout << result << "\n";
    }

    // fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y)
                                      { return x == y and x == ' '; });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
