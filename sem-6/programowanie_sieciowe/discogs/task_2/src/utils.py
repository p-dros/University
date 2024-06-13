from models import Band, Artist


def get_common_bands(artists: list[dict]):
    bands = {}

    for artist in artists:
        for band in artist.get("groups", []):
            band_id = band["id"]
            band_name = band["name"]

            if band_id not in bands:
                bands[band_id] = Band(band_id, band_name)

            bands[band_id].add_member(Artist(artist["id"], artist["name"]))

    common_bands = [band for band in bands.values() if len(band.members) != 1]

    return common_bands
