/**
 * \file
 * \brief Implementation of newlib's malloc() locking functions
 *
 * \author Copyright (C) 2015 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \date 2015-11-29
 */

#include "distortos/internal/memory/mallocLockingInitialization.hpp"

#include "distortos/internal/memory/getMallocMutex.hpp"

#include "distortos/Mutex.hpp"

namespace distortos
{

namespace internal
{

/*---------------------------------------------------------------------------------------------------------------------+
| global functions
+---------------------------------------------------------------------------------------------------------------------*/

void mallocLockingInitialization()
{
	new (&getMallocMutex()) Mutex {Mutex::Type::Recursive, Mutex::Protocol::PriorityInheritance};
}

}	// namespace internal

}	// namespace distortos
