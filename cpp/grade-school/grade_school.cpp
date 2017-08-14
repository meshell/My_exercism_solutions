//
// Created by mike on 8/15/17.
//

#include <algorithm>
#include "grade_school.h"

namespace grade_school {

    const roster_t& school::roster() const {
        return m_roster;
    }

    void school::add(const std::string& name, grade_t grade) {
        auto& students = m_roster[grade];
        const auto insert_position = std::lower_bound(students.begin(), students.end(), name);
        students.insert(insert_position, name);
    }

    student_list_t school::grade(grade_t grade) const {
        const auto it = m_roster.find(grade);
        if (it != m_roster.end()) {
            return it->second;
        }
        return {};
    }
}
