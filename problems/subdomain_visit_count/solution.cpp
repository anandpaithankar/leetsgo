class Solution {
public:
    
std::vector<std::string> ParseSubDomains(std::string &domain)
{
    std::vector<std::string> subDomains;

    subDomains.push_back(domain);

    size_t index;
    std::string subDomainStr = domain;
    while ((index = subDomainStr.find_first_of('.', 0)) != std::string::npos)
    {
        subDomainStr = subDomainStr.substr(index + 1, subDomainStr.size());
        subDomains.push_back(subDomainStr);
    }
    return subDomains;
}

std::vector<std::string> ParseCpDomain(std::string input)
{
    std::vector<std::string> result;

    std::string s = input;
    size_t index = 0;
    if ((index = s.find_first_of(' ')) != std::string::npos)
    {
        result.push_back(s.substr(0, index));
        result.push_back(s.substr(index + 1, s.size()));
    }

    return result;
}

std::vector<std::string> subdomainVisits(std::vector<std::string> &cpdomains)
{
    std::unordered_map<std::string, int> domainVisits;

    for (const auto &domainCount : cpdomains)
    {
        std::vector<std::string> values = ParseCpDomain(domainCount);
        if (values.size() < 2)
        {
            continue;
        }

        int visits = std::stoi(values[0]);
        std::string domain = values[1];

        std::cout << "Visits " << visits << " subdomain " << domain << "\n";

        auto subDomains = ParseSubDomains(domain);
        for (auto d : subDomains)
        {
            if (domainVisits.count(domain))
            {
                domainVisits[d] += visits;
            }
            else
            {
                domainVisits[d] = visits;
            }
        }
    }

    std::vector<std::string> cpoDomains;
    for (auto it : domainVisits)
    {
        std::string s = std::to_string(it.second) + " " + it.first;
        cpoDomains.push_back(s);
    }
    return cpoDomains;
}
};