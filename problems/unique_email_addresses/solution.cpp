class Solution {
public:
    
    std::string filterEmail(const std::string &email)
    {
        std::string localName;
        int i;
        for (i = 0; i < email.size(); ++i)
        {
            if (email[i] == '.')
            {
                continue;
            }
            else if (email[i] == '+' || email[i] == '@')
            {
                break;
            }
            localName += email[i];
        }

        std::string domain = std::strstr(email.c_str(), "@");
        return localName + domain;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        std::unordered_set<std::string> uniqueEmails;
        for (auto email : emails)
        {
            auto filteredEmail = filterEmail(email);
            uniqueEmails.insert(filteredEmail);
        }
        return uniqueEmails.size();
    }
};