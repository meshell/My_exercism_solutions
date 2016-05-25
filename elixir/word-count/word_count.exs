defmodule Words do
  @doc """
  Count the number of words in the sentence.

  Words are compared case-insensitively.
  """
  @spec count(String.t) :: map
  def count(sentence) do
    sentence = String.replace(sentence, ~r/[\p{Po}\p{S}]/u, " ")
    sentence = String.replace(sentence, ~r/["_"]/u, " ")
    count_from_list(String.split(sentence, " ", trim: true), %{})
  end

  defp count_from_list([head|tail], result) do
    count_from_list(tail, Map.update(result, String.downcase(head), 1, &(&1 + 1)))
  end

  defp count_from_list([], result) do
    result
  end
end
