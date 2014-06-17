/* 
 * Header that contains the plugin functionality which is not part of the plugin.h or list_api.h
 * 
 * File:   interactiveAdd.h
 * Author: drummer
 *
 * Created on 17. Juni 2014, 19:15
 */

#ifndef INTERACTIVEADD_H
#define	INTERACTIVEADD_H

#ifdef  __cplusplus
extern "C" {
#endif

    namespace HTW {
        namespace AI {
            namespace Beleg {
                namespace Plugin {

                    /**
                     * Adds a new Person interactiveally to the list.
                     */
                    void interactiveAdd(ListPerson* list);

                }
            }
        }
    }
#ifdef __cplusplus
}
#endif

#endif	/* INTERACTIVEADD_H */

