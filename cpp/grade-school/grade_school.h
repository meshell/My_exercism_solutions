//
// Created by mike on 8/15/17.
//

#ifndef GRADE_SCHOOL_GRADE_SCHOOL_H
#define GRADE_SCHOOL_GRADE_SCHOOL_H

#include <vector>
#include <map>
#include <string>

namespace grade_school {

    using grade_t = int;
    using student_list_t = std::vector<std::string>;
    using roster_t = std::map<grade_t, student_list_t>;

    class school {
    public:

        roster_t roster();

        void add(const std::string& name, grade_t grade);

        student_list_t grade(grade_t grade) const;

    private:
        roster_t m_roster;
    };

};


#endif //GRADE_SCHOOL_GRADE_SCHOOL_H
