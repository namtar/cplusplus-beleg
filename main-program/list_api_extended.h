/* 
 * File:   list_api_extended.h
 * Author: drummer
 *
 * Created on 17. Juni 2014, 20:55
 */

#ifndef LIST_API_EXTENDED_H
#define	LIST_API_EXTENDED_H

#include "list_api.h"

#ifdef  __cplusplus
extern "C" {
#endif

    namespace HTW {
        namespace AI {
            namespace Beleg {
                namespace Plugin {

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
    }
#ifdef __cplusplus
}
#endif


#endif	/* LIST_API_EXTENDED_H */

