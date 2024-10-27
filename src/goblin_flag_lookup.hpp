#pragma once
#include "from/paramdef/WORLD_MAP_POINT_PARAM_ST.hpp"
#include "from/paramdef/BONFIRE_WARP_PARAM_ST.hpp"
#include "from/params.hpp"
#include <vector>

namespace goblin {
	namespace flag {
		static constexpr int AshenCapital = 118;
		static constexpr int FarumAzula = 62008;
		static constexpr int Haligtree = 62009;
		static constexpr int WestLimgrave = 62010;
		static constexpr int WeepingPeninsula = 62011;
		static constexpr int EastLimgrave = 62012;
		static constexpr int EastLiurnia = 62020;
		static constexpr int NorthLiurnia = 62021;
		static constexpr int WestLiurnia = 62022;
		static constexpr int Altus = 62030;
		static constexpr int Leyndell = 62031;
		static constexpr int Gelmir = 62032;
		static constexpr int Caelid = 62040;
		static constexpr int Dragonbarrow = 62041;
		static constexpr int MountaintopsWest = 62050;
		static constexpr int MountaintopsEast = 62051;
		static constexpr int Snowfields = 62052;
		static constexpr int Ainsel = 62060;
		static constexpr int LakeOfRot = 62061;
		static constexpr int Mohgwyn = 62062;
		static constexpr int Siofra = 62063;
		static constexpr int Deeproot = 62064;
		static constexpr int GravesitePlain = 62080;
		static constexpr int ScaduAltus = 62081;
		static constexpr int SouthernShore = 62082;
		static constexpr int RauhRuins = 62083;
		static constexpr int Abyss = 62084;
	}

	namespace param {
		/// <summary>
		/// TextId 0 are ignored
		/// </summary>
		/// <param name="row">A single row from WORLD_MAP_POINT_PARAM_ST</param>
		/// <param name="offset">At which textId to start</param>
		/// <returns>Whether row contains these TextIds</returns>
		bool ContainsTextId(from::paramdef::WORLD_MAP_POINT_PARAM_ST& row, int offset, int firstTextId, int secondTextId, int thirdTextId);
		bool ContainsTextId(from::paramdef::BONFIRE_WARP_PARAM_ST& row, int offset, int firstTextId, int secondTextId, int thirdTextId);
	}

	namespace map {
		struct MapChunk {
			int X;
			int Y;
			int Z;
			// Constructor for initializing MapChunk
			MapChunk(int x, int y, int z) :X(x), Y(y), Z(z) {}
			MapChunk(int x, int y) :X(x), Y(y), Z(0) {}
			MapChunk(int x) :X(x), Y(0), Z(0) {}

			// If is all same
			bool operator==(const MapChunk& other) const {
				return X == other.X && Y == other.Y && Z == other.Z;
			}

			// Check if all same, return reverse
			bool operator!=(const MapChunk& other) const {
				return !(*this == other);
			}
		};
		struct MapFragments {
			int mapFragmentId;
			std::vector<MapChunk> mapFragmentChunks;

			MapFragments(int fragmentId, std::vector<MapChunk> mapChunks)
				: mapFragmentId(fragmentId), mapFragmentChunks(mapChunks) {}
		};		
		int GetMapFlag(MapChunk location);
	}
}

using namespace goblin::map;
static std::vector<MapFragments> MapList{
MapFragments(goblin::flag::WestLimgrave,
	{
	MapChunk(10), // Stormveil
	MapChunk(10, 1), // Chapel
	MapChunk(30, 11), // Deathtouched Catacombs
	MapChunk(31, 17), // Highroad Cave
	MapChunk(30,4), // Murkwater Catacombs
	MapChunk(31), // Murkwater Cave
	MapChunk(32,1), // Limgrave Tunnels
	MapChunk(31,3), // Groveside Cave
	MapChunk(31,15), // Coastal Cave
	MapChunk(30,2), // Stormfoot Catacombs
	MapChunk(18), // Stranded Graveyard
	MapChunk(60, 40, 39), // 20_19 Stormveil upper left corner
	MapChunk(60, 40, 38), // 20_19 Stormveil lower left corner
	MapChunk(60, 41, 39), // 20_19 Stormveil upper right corner
	MapChunk(60, 41, 38), // 20_19 Stormveil lower right corner
	MapChunk(60, 41, 37), // 20_18 Stormveil beach upper right corner
	MapChunk(60, 41, 36), // 20_18 Stormveil beach lower right corner
	MapChunk(60, 42, 40), // 21_20 Limgrave Colosseum lower left corner
	MapChunk(60, 42, 39), // 21_19 Warmaster upper left corner
	MapChunk(60, 42, 38), // 21_19 Warmaster lower left corner
	MapChunk(60, 42, 37), // 21_18 Agheel Lake upper left corner
	MapChunk(60, 42, 36), // 21_18 Agheel Lake lower left corner
	MapChunk(60, 42, 35), // 21_17 Gravitas upper left corner
	MapChunk(60, 43, 40), // 21_20 Limgrave Colosseum lower right corner
	MapChunk(60, 43, 39), // 21_19 Warmaster upper right corner
	MapChunk(60, 43, 38), // 21_19 Warmaster lower right corner
	MapChunk(60, 43, 37), // 21_18 Agheel Lake upper right corner
	MapChunk(60, 43, 36), // 21_18 Agheel Lake lower right corner
	MapChunk(60, 43, 35), // 21_17 Gravitas upper right corner
	MapChunk(60, 44, 40), // 22_20 Divine Tower lower left corner
	MapChunk(60, 44, 37), // 22_18 Witchbane Ruins upper left corner
	MapChunk(60, 44, 36), // 22_18 Witchbane Ruins lower left corner
	MapChunk(60, 44, 35), // 22_17 Bridge of Sacrifice upper left corner
	}),
MapFragments(goblin::flag::WeepingPeninsula,
	{
	MapChunk(32), // Morne Tunnel
	MapChunk(30), // Tombswards Catacombs
	MapChunk(31,1), // Earthbore Cave
	MapChunk(30,1), // Impaler's Catacombs
	MapChunk(60, 40, 33), // 20_16 Isolated Merchant upper left corner
	MapChunk(60, 40, 32), // 20_16 Isolated Merchant lower left corner
	MapChunk(60, 41, 33), // 20_16 Isolated Merchant upper right corner
	MapChunk(60, 41, 32), // 20_16 Isolated Merchant lower right corner
	MapChunk(60, 42, 34), // 21_17 Gravitas lower left corner
	MapChunk(60, 42, 33), // 21_16 Weeping Erdtree upper left corner
	MapChunk(60, 42, 32), // 21_16 Weeping Erdtree lower left corner
	MapChunk(60, 43, 34), // 21_17 Gravitas lower right corner
	MapChunk(60, 43, 33), // 21_16 Weeping Erdtree upper right corner
	MapChunk(60, 43, 32), // 21_16 Weeping Erdtree lower right corner
	MapChunk(60, 43, 31), // 21_15 Castle Morne upper right corner
	MapChunk(60, 43, 30), // 21_15 Castle Morne lower right corner
	MapChunk(60, 44, 34), // 21_17 Bridge of Sacrifice lower left corner
	MapChunk(60, 44, 33), // 22_16 Morne Rampart upper left corner
	MapChunk(60, 44, 32), // 22_16 Morne Rampart lower left corner
	MapChunk(60, 44, 31), // 22_16 Morne Swamp upper left corner
	MapChunk(60, 45, 34), // 21_17 Bridge of Sacrifice lower right corner
	MapChunk(60, 45, 33), // 22_16 Morne Rampart upper right corner
	MapChunk(60, 45, 32), // 22_16 Morne Rampart lower right corner
	MapChunk(60, 45, 31), // 22_16 Morne Swamp upper right corner
	}),
MapFragments(goblin::flag::EastLimgrave,
	{
	MapChunk(30,14), // Minor Erdtree Catacombs
	MapChunk(32,7), // Gael Tunnel
	MapChunk(31,21), // Gaol Cave
	MapChunk(60, 44, 39), // fok of
	MapChunk(60, 44, 38),
	MapChunk(60, 45, 40),
	MapChunk(60, 45, 39),
	MapChunk(60, 45, 38),
	MapChunk(60, 45, 37),
	MapChunk(60, 45, 36),
	MapChunk(60, 45, 35),
	MapChunk(60, 46, 41),
	MapChunk(60, 46, 40),
	MapChunk(60, 46, 39),
	MapChunk(60, 46, 38),
	MapChunk(60, 46, 37),
	MapChunk(60, 46, 36),
	MapChunk(60, 47, 40),
	MapChunk(60, 47, 39),
	MapChunk(60, 47, 38),
	MapChunk(60, 47, 37),
	MapChunk(60, 48, 40),
	MapChunk(60, 48, 39),
	}),
MapFragments(goblin::flag::Caelid,
	{
	MapChunk(34,13), // Divine tower of Caelid
	MapChunk(30,15), // Caelid Catacombs
	MapChunk(30,16), // War-Dead Catacombs
	MapChunk(31,20), // Abandoned Cave
	MapChunk(32,8), // Sellia Crystal Tunnel
	MapChunk(31,11), // Sellia Hideaway
	MapChunk(60, 48, 39),	// 24_19 Aeonia Lake upper left corner
	MapChunk(60, 48, 38),	// 24_19 Aeonia Lake lower left corner
	MapChunk(60, 48, 37),	// 24_18 Ekzykes crossroads upper left corner
	MapChunk(60, 48, 36),	// 24_18 Ekzykes crossroads lower left corner
	MapChunk(60, 49, 39),	// 24_19 Aeonia Lake upper right corner
	MapChunk(60, 49, 38),	// 24_19 Aeonia Lake lower right corner
	MapChunk(60, 49, 37),	// 24_18 Ekzykes crossroads upper right corner
	MapChunk(60, 49, 36),	// 24_18 Ekzykes crossroads lower right corner
	MapChunk(60, 50, 39),	// 25_19 Church of the Plague upper left corner
	MapChunk(60, 50, 38),	// 25_19 Church of the Plague lower left corner
	MapChunk(60, 50, 37),	// 25_18 Redmane Castle upper left corner
	MapChunk(60, 50, 36),	// 25_18 Redmane Castle lower left corner
	MapChunk(60, 51, 39),	// 25_19 Church of the Plague upper right corner
	MapChunk(60, 51, 38),	// 25_19 Church of the Plague lower right corner
	MapChunk(60, 51, 37),	// 25_18 Redmane Castle upper right corner
	MapChunk(60, 51, 36),	// 25_18 Redmane Castle lower right corner
	MapChunk(60, 52, 39),	// 26_19 Redmane Beach upper left corner
	MapChunk(60, 52, 38),	// 26_19 Redmane Beach lower left corner
	MapChunk(60, 52, 37),	// 26_19 Redmane Beach lower upper left corner
	MapChunk(60, 52, 36),	// 26_19 Redmane Beach lower lower left corner
	MapChunk(60, 53, 39),	// 26_19 Redmane Beach upper right corner
	MapChunk(60, 53, 38),	// 26_19 Redmane Beach lower right corner
	MapChunk(60, 53, 37)	// 26_19 Redmane Beach lower upper right corner
	}),
MapFragments(goblin::flag::Dragonbarrow,
	{
	MapChunk(60, 47, 42),	// 23_21 Caelid Colosseum upper left corner
	MapChunk(60, 47, 41),	// 23_20 Caelid Colosseum path
	MapChunk(60, 48, 41),	// 24_20 Caelid Merchant
	MapChunk(60, 49, 41),	// 24_20 Caelid Divine Tower north
	MapChunk(60, 49, 40),	// 24_20 Caelid Divine Tower crossing
	MapChunk(60, 50, 41),
	MapChunk(60, 50, 40),
	MapChunk(60, 51, 43),
	MapChunk(60, 51, 42),
	MapChunk(60, 51, 41),
	MapChunk(60, 51, 40),
	MapChunk(60, 52, 43),
	MapChunk(60, 52, 42),
	MapChunk(60, 52, 41),
	MapChunk(60, 52, 40),
	MapChunk(60, 53, 43),
	MapChunk(60, 53, 42),
	MapChunk(60, 53, 41),
	MapChunk(60, 53, 40),
	}),
MapFragments(goblin::flag::EastLiurnia,
	{
	MapChunk(31, 4), // Stillwater Cave
	MapChunk(30, 5), // Black Knife Catacombs
	MapChunk(31, 5), // Lakeside Crystal Cave
	MapChunk(30, 6), // Cliffbottom Catacombs
	MapChunk(34, 11), // Divine Tower of Liurnia
	MapChunk(39, 20), // Ruin-Strewn Precipice
	MapChunk(60, 38, 50),
	MapChunk(60, 37, 49),
	MapChunk(60, 38, 49),
	MapChunk(60, 39, 49),
	MapChunk(60, 36, 48),
	MapChunk(60, 37, 48),
	MapChunk(60, 38, 48),
	MapChunk(60, 39, 48),
	MapChunk(60, 37, 47),
	MapChunk(60, 38, 47),
	MapChunk(60, 39, 47),
	MapChunk(60, 37, 46),
	MapChunk(60, 38, 46),
	MapChunk(60, 39, 46),
	MapChunk(60, 38, 45),
	MapChunk(60, 39, 45),
	MapChunk(60, 40, 45),
	MapChunk(60, 41, 45),
	MapChunk(60, 38, 44),
	MapChunk(60, 39, 44),
	MapChunk(60, 40, 44),
	MapChunk(60, 41, 44),
	MapChunk(60, 38, 43),
	MapChunk(60, 39, 43),
	MapChunk(60, 40, 43),
	MapChunk(60, 38, 42),
	MapChunk(60, 39, 42),
	MapChunk(60, 40, 42),
	MapChunk(60, 41, 42),
	MapChunk(60, 36, 41),
	MapChunk(60, 37, 41),
	MapChunk(60, 38, 41),
	MapChunk(60, 39, 41),
	MapChunk(60, 40, 41),
	MapChunk(60, 41, 41),
	MapChunk(60, 36, 40),
	MapChunk(60, 37, 40),
	MapChunk(60, 38, 40),
	MapChunk(60, 39, 40),
	MapChunk(60, 40, 40),
	MapChunk(60, 41, 40),
	}),
MapFragments(goblin::flag::NorthLiurnia,
	{
	MapChunk(14), // Academy of Raya Lucaria
	MapChunk(31, 6), // Academy Crystal Cave
	MapChunk(60, 35, 48),
	MapChunk(60, 35, 47),
	MapChunk(60, 36, 47),
	MapChunk(60, 34, 46),
	MapChunk(60, 35, 46),
	MapChunk(60, 36, 46),
	MapChunk(60, 34, 45),
	MapChunk(60, 35, 45),
	MapChunk(60, 36, 45),
	MapChunk(60, 37, 45),
	MapChunk(60, 34, 44),
	MapChunk(60, 35, 44),
	MapChunk(60, 36, 44),
	MapChunk(60, 37, 44),
	MapChunk(60, 35, 43),
	MapChunk(60, 36, 43),
	MapChunk(60, 37, 43),
	MapChunk(60, 36, 42),
	MapChunk(60, 37, 42),
	}),
MapFragments(goblin::flag::WestLiurnia,
	{
	MapChunk(30, 3), // Road's End Catacombs
	MapChunk(60, 34, 51),
	MapChunk(60, 35, 51),
	MapChunk(60, 34, 50),
	MapChunk(60, 35, 50),
	MapChunk(60, 36, 50),
	MapChunk(60, 37, 50),
	MapChunk(60, 34, 49),
	MapChunk(60, 35, 49),
	MapChunk(60, 36, 49),
	MapChunk(60, 33, 48),
	MapChunk(60, 34, 48),
	MapChunk(60, 33, 47),
	MapChunk(60, 34, 47),
	MapChunk(60, 33, 46),
	MapChunk(60, 33, 45),
	MapChunk(60, 33, 44),
	MapChunk(60, 33, 43),
	MapChunk(60, 34, 43),
	MapChunk(60, 33, 42),
	MapChunk(60, 34, 42),
	MapChunk(60, 35, 42),
	MapChunk(60, 33, 41),
	MapChunk(60, 34, 41),
	MapChunk(60, 35, 41),
	MapChunk(60, 33, 40),
	MapChunk(60, 34, 40),
	MapChunk(60, 35, 40),
	}),
MapFragments(goblin::flag::Altus,
	{
	MapChunk(30,8), // Sainted Hero's Grave
	MapChunk(32,5), // Altus Tunnel
	MapChunk(31,18), // Perfumer's Grotto
	MapChunk(60, 40, 55),
	MapChunk(60, 41, 55),
	MapChunk(60, 42, 55),
	MapChunk(60, 40, 54),
	MapChunk(60, 41, 54),
	MapChunk(60, 42, 54),
	MapChunk(60, 43, 54),
	MapChunk(60, 40, 53),
	MapChunk(60, 41, 53),
	MapChunk(60, 42, 53),
	MapChunk(60, 39, 52),
	MapChunk(60, 40, 52),
	MapChunk(60, 41, 52),
	MapChunk(60, 39, 51),
	MapChunk(60, 40, 51),
	MapChunk(60, 41, 51),
	MapChunk(60, 39, 50),
	MapChunk(60, 40, 50),
	MapChunk(60, 41, 50),
	}),
MapFragments(goblin::flag::Leyndell,
	{
	MapChunk(11), // Leyndell Capital
	MapChunk(35), // Leyndell Catacombs
	MapChunk(30,10), // Auriza Hero's Grave
	MapChunk(30,13), // Auriza Side Tomb
	// Inner wall stuff
	MapChunk(60, 43, 53),
	MapChunk(60, 44, 53),
	MapChunk(60, 45, 53),
	MapChunk(60, 42, 52),
	MapChunk(60, 43, 52),
	MapChunk(60, 44, 52),
	MapChunk(60, 45, 52),
	MapChunk(60, 42, 51),
	MapChunk(60, 43, 51),
	MapChunk(60, 44, 51),
	MapChunk(60, 45, 51),
	MapChunk(60, 46, 51),
	MapChunk(60, 42, 50),
	MapChunk(60, 43, 50),
	MapChunk(60, 43, 49),
	}),
MapFragments(goblin::flag::Gelmir,
	{
	MapChunk(16), // Volcano Manor
	MapChunk(32,4), // Old Altus Tunnel
	MapChunk(30,7), // Wyndham Catacombs
	MapChunk(31,7), // Seethewater Cave
	MapChunk(30,9), // Gelmir Hero's Grave
	MapChunk(31,9), // Volcano Cave
	MapChunk(30,12), // Unsightly Catacombs
	MapChunk(60, 34, 55), // 17_27 Seethewater upper left corner
	MapChunk(60, 34, 54), // 17_27 Seethewater lower left corner
	MapChunk(60, 34, 53), // 17_26 Magma Wyrm upper left corner
	MapChunk(60, 34, 52), // 17_26 Magma Wyrm lower left corner
	MapChunk(60, 35, 55), // 17_27 Seethewater upper right corner
	MapChunk(60, 35, 54), // 17_27 Seethewater lower right corner
	MapChunk(60, 35, 53), // 17_26 Magma Wyrm lower left corner
	MapChunk(60, 35, 52), // 17_26 Magma Wyrm upper left corner
	MapChunk(60, 36, 55), // 18_27 Volcano Cave upper left corner
	MapChunk(60, 36, 54), // 18_27 Volcano Cave lower left corner
	MapChunk(60, 36, 53), // 18_26 Volcano Manor upper left corner
	MapChunk(60, 36, 52), // 18_26 Volcano Manor lower left corner
	MapChunk(60, 36, 51), // 18_25 Abandonded coffin upper left corner
	MapChunk(60, 37, 55), // 18_27 Volcano Cave upper right corner
	MapChunk(60, 37, 54), // 18_27 Volcano Cave lower right corner
	MapChunk(60, 37, 53), // 18_26 Volcano Manor upper right corner
	MapChunk(60, 37, 52), // 18_26 Volcano Manor lower right corner
	MapChunk(60, 37, 51), // 18_25 Abandonded coffin upper right corner
	MapChunk(60, 38, 55), // 19_27 Shaded Castle upper left corner
	MapChunk(60, 38, 54), // 19_27 Shaded Castle lower left corner
	MapChunk(60, 38, 53), // 19_26 Bridge of Iniquity upper left corner
	MapChunk(60, 38, 52), // 19_26 Bridge of Iniquity lower left corner
	MapChunk(60, 38, 51), // 19_25 Erdtree Gazing Hill  upper left corner
	MapChunk(60, 39, 55), // 19_27 Shaded Castle upper right corner
	MapChunk(60, 39, 54), // 19_27 Shaded Castle lower right corner
	MapChunk(60, 39, 53), // 19_26 Bridge of Iniquity upper right corner
	}),
MapFragments(goblin::flag::MountaintopsWest,
	{
	MapChunk(34, 14), // Divine Tower of East Altus
	MapChunk(30, 17), // Giant-Conquering Hero's Grave
	MapChunk(30, 18), // Giants' Mountaintop Catacombs
	MapChunk(60, 47, 51), // Path to Rold
	MapChunk(60, 48, 51), // Path to Rold
	MapChunk(60, 49, 51), // Path to Rold
	MapChunk(60, 49, 52), // Path to Rold
	MapChunk(60, 49, 53), // Rold
	MapChunk(60, 50, 53),
	MapChunk(60, 50, 54),
	MapChunk(60, 51, 55),
	MapChunk(60, 51, 56),
	MapChunk(60, 52, 56),
	MapChunk(60, 50, 57),
	MapChunk(60, 51, 57),
	MapChunk(60, 52, 57),
	MapChunk(60, 51, 58),
	MapChunk(60, 52, 58),
	}),
MapFragments(goblin::flag::MountaintopsEast,
	{
	MapChunk(31, 22), // Spiritcaller Cave
	MapChunk(60, 53, 58),
	MapChunk(60, 53, 57),
	MapChunk(60, 54, 57),
	MapChunk(60, 53, 56),
	MapChunk(60, 54, 56),
	MapChunk(60, 52, 55),
	MapChunk(60, 53, 55),
	MapChunk(60, 54, 55),
	MapChunk(60, 51, 54),
	MapChunk(60, 52, 54),
	MapChunk(60, 53, 54),
	MapChunk(60, 51, 53),
	MapChunk(60, 52, 53),
	MapChunk(60, 53, 53),
	MapChunk(60, 54, 53),
	MapChunk(60, 51, 52),
	MapChunk(60, 52, 52),
	MapChunk(60, 53, 52),
	}),
MapFragments(goblin::flag::Snowfields,
	{
	MapChunk(31, 12), // Cave of Forlorn
	MapChunk(31, 11), // Yelough Anix Ruins
	MapChunk(30, 10), // Consecrated Snowfield Catacombs
	MapChunk(30, 20), // Hidden Path to the Haligtree
	MapChunk(60, 47, 58),
	MapChunk(60, 46, 57),
	MapChunk(60, 47, 57),
	MapChunk(60, 48, 57),
	MapChunk(60, 49, 57),
	MapChunk(60, 47, 56),
	MapChunk(60, 48, 56),
	MapChunk(60, 49, 56),
	MapChunk(60, 47, 55),
	MapChunk(60, 48, 55),
	MapChunk(60, 49, 55),
	MapChunk(60, 50, 55),
	MapChunk(60, 48, 54),
	MapChunk(60, 49, 54),
	}),
MapFragments(goblin::flag::Siofra,
	{
		MapChunk(12,2), // Siofra River / Nokron
		MapChunk(12,7), // Nokron Start
		MapChunk(12,8), // Regal Ancestor Spirit Chamber
		MapChunk(12,9), // Regal Ancestor Spirit Chamber
	}),
MapFragments(goblin::flag::Mohgwyn,
	{
		MapChunk(12,5), // Mohgwyn
	}),
MapFragments(goblin::flag::Ainsel,
	{
		MapChunk(12,1), // Ainsel River / Lake of Rot
	}),
MapFragments(goblin::flag::LakeOfRot,
	{
		MapChunk(12,4), // Astel's Chamber
	}),
MapFragments(goblin::flag::Haligtree,
	{
		MapChunk(15),
	}),
MapFragments(goblin::flag::FarumAzula,
	{
		MapChunk(13),
	}),
MapFragments(goblin::flag::Deeproot,
	{
		MapChunk(12,3),
	}),
MapFragments(goblin::flag::AshenCapital,
	{
	MapChunk(11, 5), // Ashen Capital
	MapChunk(19), // Stone Platform
	}),
MapFragments(goblin::flag::GravesitePlain,
	{
	}),
MapFragments(goblin::flag::ScaduAltus,
	{
	}),
MapFragments(goblin::flag::SouthernShore,
	{
	}),
MapFragments(goblin::flag::RauhRuins,
	{
	}),
MapFragments(goblin::flag::Abyss,
	{
	}),
};
