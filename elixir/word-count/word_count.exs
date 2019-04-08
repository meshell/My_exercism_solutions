defmodule Words do
  @doc """
  Count the number of words in the sentence.

  Words are compared case-insensitively.
  """
  @spec count(String.t) :: map
  def count(sentence) do
    sentence
    |> String.replace(~r/[\p{Po}\p{S}]/u, " ")
    |> String.replace(~r/["_"]/u, " ")
    |> String.split(" ", trim: true)
    |> Enum.reduce(%{}, fn (word, result) -> Map.update(result, String.downcase(word), 1, &(&1 + 1)) end )
  end
end