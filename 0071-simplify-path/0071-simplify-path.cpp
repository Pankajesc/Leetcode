class Solution
{
public:
    std::string simplifyPath(std::string path)
    {
        if (path.size() == 1)
        {
            return path;
        }
        std::string result;
        std::stack<std::string> stk;
        std::string temp;
        for (int i = 0; i < path.size(); i++)
        {
            temp.clear();

            while (path[i] == '/')
            {
                i++;
            }

            while (i < path.size() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }

            if (temp == "..")
            {
                if (!stk.empty())
                {
                    stk.pop();
                }
            }
            else
            {
                if (temp != "." && temp != "")
                {
                    stk.push(temp);
                }
            }
        }
        std::stack<std::string> reverse;
        while (!stk.empty())
        {
            reverse.push(stk.top());
            stk.pop();
        }

        while (!reverse.empty())
        {
            result += "/" + reverse.top();
            reverse.pop();
        }

        return result.empty() ? "/" : result;
    }
};