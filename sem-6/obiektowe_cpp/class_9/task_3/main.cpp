#include <iostream>
#include <memory>
#include <utility>
#include <vector>

struct MediaAsset {
  virtual ~MediaAsset() = default;
};

struct Song : public MediaAsset {
  std::wstring artist;
  std::wstring title;

  Song(const std::wstring& artist_, const std::wstring& title_)
      : artist{artist_}, title{title_} {
    std::wcout << L"Konstruktor Song dla: " << artist << L", " << title
               << L"\n";
  }

  ~Song() {
    std::wcout << L"Destruktor Song dla: " << artist << L", " << title << L"\n";
  }
};

struct Photo : public MediaAsset {
  std::wstring date;
  std::wstring location;
  std::wstring subject;
  Photo(const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_)
      : date{date_}, location{location_}, subject{subject_} {
  }
};

std::unique_ptr<Song> SongFactory(const std::wstring& artist,
                                  const std::wstring& title) {
  return std::make_unique<Song>(artist, title);
}

int main() {
  std::vector<std::unique_ptr<Song>> songs;
  songs.push_back(std::make_unique<Song>(L"Michael Jackson", L"Beat It"));
  songs.push_back(std::make_unique<Song>(L"Queen", L"Bohemian Rhapsody"));
  songs.push_back(std::make_unique<Song>(L"AC/DC", L"Back in Black"));

  // compiler error when not reference
  for (const auto& song : songs) {
    std::wcout << L"Artist: " << song->artist << L" Title: " << song->title
               << std::endl;
  }
  return 0;
}