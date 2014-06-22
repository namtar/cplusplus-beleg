/* 
 * File:   list_api_extended.h
 * Author: drummer
 *
 * Created on 17. Juni 2014, 20:55
 */

#ifndef LIST_API_EXTENDED_H
#define	LIST_API_EXTENDED_H

#include "list_api.h"

namespace HTW {
    namespace AI {
        namespace Beleg {

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

