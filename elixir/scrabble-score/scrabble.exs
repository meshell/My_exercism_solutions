defmodule Scrabble do
  @doc """
  Calculate the scrabble score for the word.
  """
@scores [
  {1, 'AEIOULNRST'},
  {2, 'DG'},
  {3, 'BCMP'},
  {4, 'FHVWY'},
  {5, 'K'},
  {8, 'JX'},
  {10, 'QZ'}
]

  @spec score(String.t) :: non_neg_integer
  def score(word) do
    get_score_for_char = fn
      char -> {s, _} = Enum.find(@scores, {0, []}, fn {_, list} -> char in list end)
      s
    end
    word
    |> String.upcase
    |> to_charlist
    |> Enum.reduce(0, fn(c, acc) -> acc + get_score_for_char.(c) end)
  end
end
