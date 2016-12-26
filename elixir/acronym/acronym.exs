defmodule Acronym do
  @doc """
  Generate an acronym from a string.
  "This is a string" => "TIAS"
  """
  @spec abbreviate(string) :: String.t()
  def abbreviate(string) do
    get_acronym_letters_from_word = &(String.upcase(String.at(&1,0)) <> String.replace(String.slice(&1, 1..-1), ~r/[^A-Z]/, ""))
    string |>
    String.split(~r/[-|\s]/) |>
    Enum.map(get_acronym_letters_from_word) |>
    Enum.join()
  end
end
