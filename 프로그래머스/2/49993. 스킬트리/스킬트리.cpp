#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, char> ParentTree;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 1; i < skill.length(); i++) {
        ParentTree[skill[i]] = skill[i - 1];
    }

    for (const auto &SkillTree: skill_trees) {
        map<char, bool> HasSkill;

        bool CanLearn = true;
        for (const auto &Skill: SkillTree) {
            // 트리에 정보가 없는 경우는 그냥 배워도 된다.
            if (ParentTree.find(Skill) == ParentTree.end()) {
                HasSkill[Skill] = true;
            } else {
                if (!HasSkill[ParentTree[Skill]]) {
                    CanLearn = false;
                    break;
                }
                HasSkill[Skill] = true;
            }
        }

        if (CanLearn) {
            answer += 1;
        }
    }

    return answer;
}