#ifndef DATABASE_H
#define DATABASE_H

#include "main.h"

typedef struct {
  uint16_t _version;
  uint16_t users;
} __attribute__((packed)) database_head_t;

typedef struct {
  char username[64];
  uint64_t password;
} __attribute__((packed)) database_segment_t;

class Database {
private:
  FILE *dbfile;
  std::mutex mtx;
public:
  Database(const char *filepath);
  ~Database();

  void check(void);

  bool create(const char *username, const char *password);
  bool exists(const char *username);
  bool authorize(const char *username, const char *password);
};

#endif // DATABASE_H
