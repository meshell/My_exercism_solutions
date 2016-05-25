defmodule Anagram do
  @doc """
  Returns all candidates that are anagrams of, but not equal to, 'base'.
  """
  @spec match(String.t, [String.t]) :: [String.t]
  def match(base, candidates) do
    is_anagram_of_base = fn candidate -> anagrams(base, candidate) end
    candidates
    |> Enum.reduce( [], fn (candidate, result) -> cond do
      is_anagram_of_base.(candidate) -> result ++ [candidate]
      true -> result
    end end)
  end

  @spec anagrams(String.t, String.t) :: boolean
  defp anagrams(base, candidate) do
    base_lowercase = String.downcase(base)
    candidate_lowercase = String.downcase(candidate)
    (base_lowercase != candidate_lowercase) and
    (Enum.sort(String.to_char_list(base_lowercase)) == Enum.sort(String.to_char_list(candidate_lowercase)))
  end
end
