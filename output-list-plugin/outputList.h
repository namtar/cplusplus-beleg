/* 
 * Header file that contains the plugin functionality which is not part of the plugin.h or list_api.h
 * 
 * File:   outputList.h
 * Author: drummer
 *
 * Created on 17. Juni 2014, 19:19
 */

#ifndef OUTPUTLIST_H
#define	OUTPUTLIST_H


#ifdef  __cplusplus
extern "C" {
#endif

    namespace HTW {
        namespace AI {
            namespace Beleg {
                namespace Plugin {

                    /**
                     * Outputs all elements of the list.
                     * 
                     * @param list the list which cointains the elements to be outputted
                     */
                    void outputList(ListPerson* list);
                }
            }
        }
    }
#ifdef __cplusplus
}
#endif

#endif	/* OUTPUTLIST_H */

