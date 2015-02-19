/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2015 EQEMu Development Team (http://eqemulator.net)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef COMMON_ITEM_INSTANCE_H
#define COMMON_ITEM_INSTANCE_H

#include "item_data.h"
#include <string>
#include <memory>
#include <map>

namespace EQEmu
{
	class ItemInstance
	{
	public:
		ItemInstance();
		ItemInstance(const ItemData* idata);
		ItemInstance(const ItemData* idata, int16 charges);
		~ItemInstance();

		std::shared_ptr<ItemInstance> GetItem(int index);
	private:
		const ItemData *base_item_;
		ItemData *modified_item_;
		int16 charges_;
		uint32 color_;
		bool attuned_;
		std::string custom_data_;
		uint32 ornament_idfile_;
		uint32 ornament_icon_;
		uint32 ornament_hero_model_;
		uint64 tracking_id_;
		std::map<int, std::shared_ptr<ItemInstance>> contents_;
	};

} // EQEmu

#endif
