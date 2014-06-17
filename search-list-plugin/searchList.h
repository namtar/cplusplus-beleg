/* 
 * Header file that contains the functionality which is not part of the plugin.h or list_api.h
 * 
 * File:   searchList.h
 * Author: drummer
 *
 * Created on 17. Juni 2014, 19:22
 */

#ifndef SEARCHLIST_H
#define	SEARCHLIST_H

#ifdef  __cplusplus
extern "C" {
#endif

    namespace HTW {
        namespace AI {
            namespace Beleg {
                namespace Plugin {

                    /**
                     * Searches the given list for a name.
                     * 
                     * @param list the list to be searched
                     */
                    void searchList(ListPerson* list);
                }
            }
        }
    }
#ifdef __cplusplus
}
#endif

#endif	/* SEARCHLIST_H */

