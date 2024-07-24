#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <mutex>

namespace Bankaccount {
class Bankaccount {
public:
  void open();
  void close();
  int balance() const;
  void deposit(int amount);
  void withdraw(int amount);

private:
  bool m_open{};
  int m_balance{0};
  mutable std::mutex m_account_mutex;

}; // class Bankaccount

} // namespace Bankaccount

#endif // BANK_ACCOUNT_H