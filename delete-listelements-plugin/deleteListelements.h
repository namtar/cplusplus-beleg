/* 
 * Header for the plugin functionality which is not part of the plugin.h or list_api.h
 * 
 * File:   deleteListelements.h
 * Author: drummer
 *
 * Created on 17. Juni 2014, 19:04
 */

#ifndef DELETELISTELEMENTS_H
#define	DELETELISTELEMENTS_H

#ifdef  __cplusplus
extern "C" {
#endif

    namespace HTW {
        namespace AI {
            namespace Beleg {
                namespace Plugin {

                    /**
                     * Deletes all elements in the list.
                     * 
                     * @param list the list which contains the elements to be deleted
                     */
                    void deleteAllListelements(ListPerson* list);

                }
            }
        }
    }
#ifdef __cplusplus
}
#endif

#endif	/* DELETELISTELEMENTS_H */

