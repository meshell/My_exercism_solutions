defmodule Acronym do
  @doc """
  Generate an acronym from a string.
  "This is a string" => "TIAS"
  """
  @spec abbreviate(string) :: String.t()
  def abbreviate(string) do
    string |>
    String.split(~r/[-|\s]/) |>
    Enum.map(&get_acronym_letters_from_word/1) |>
    Enum.join()
  end

  defp get_acronym_letters_from_word(string) do
    String.upcase(String.at(string,0)) <> String.replace(String.slice(string, 1..-1), ~r/[^A-Z]/, "")
  end
end
