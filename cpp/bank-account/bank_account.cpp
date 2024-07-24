#include "bank_account.h"

#include <stdexcept>

namespace Bankaccount {

void Bankaccount::open() {
  std::scoped_lock lock(m_account_mutex);
  if (not m_open) {
    m_open = true;
    m_balance = 0;
  } else {
    throw std::runtime_error{"Bankaccount is already open."};
  }
}

void Bankaccount::close() {
  std::scoped_lock lock(m_account_mutex);
  if (m_open) {
    m_open = false;
  } else {
    throw std::runtime_error{"Bankaccount is not open."};
  }
}

int Bankaccount::balance() const {
  std::scoped_lock lock(m_account_mutex);
  if (m_open) {
    return m_balance;
  } else {
    throw std::runtime_error{"Bankaccount is closed."};
  }
}

void Bankaccount::deposit(int amount) {

  std::scoped_lock lock(m_account_mutex);

  if (m_open) {
    if (amount < 0)
      throw std::runtime_error{"Cannot deposit negative value."};
    m_balance += amount;
  } else {
    throw std::runtime_error{"Bankaccount is closed."};
  }
}

void Bankaccount::withdraw(int amount) {
  std::scoped_lock lock(m_account_mutex);

  if (m_open) {
    if (amount < 0)
      throw std::runtime_error{"Cannot withdraw negative value."};
    if (m_balance >= amount) {
      m_balance -= amount;
    } else {
      throw std::runtime_error{"Not enough money to withdraw."};
    }
  } else {
    throw std::runtime_error{"Bankaccount is closed."};
  }
}

} // namespace Bankaccount