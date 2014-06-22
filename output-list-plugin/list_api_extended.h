/* 
 * File:   list_api_extended.h
 * Author: drummer
 *
 * Created on 17. Juni 2014, 20:55
 */

#ifndef LIST_API_EXTENDED_H
#define	LIST_API_EXTENDED_H

#include "list_api.h"
#include <string>

namespace HTW {
    namespace AI {
        namespace Beleg {

            /**
             * Maps a given Sex enum to string.
             * 
             * @param sex the sex enum to be mapped
             * @return the mapped string
             */
            std::string mapSexToString(Sex sex);

            /**
             * Maps a given department enum to string
             * 
             * @param department the department enum to be mapped
             * @return the mapped string
             */
            std::string mapDepartmentToString(Department department);

            /**
             * Outputs a person
             * 
             * @param person the Person the be outputted.
             */
            void outputPerson(Person* person);

            /**
             * Outputs the table header for a person output.
             */
            void outputPersonTableHeader();
        }
    }
}

#endif	/* LIST_API_EXTENDED_H */

