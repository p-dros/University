class Artist:
    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name


class Band:
    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name
        self.members = []

    def add_member(self, artist: Artist):
        self.members.append(artist)

    def __str__(self):
        member_names = ", ".join(member.name for member in self.members)

        return f"Band: {self.name}\nMembers: {member_names}"
