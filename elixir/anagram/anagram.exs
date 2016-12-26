defmodule Anagram do
  @doc """
  Returns all candidates that are anagrams of, but not equal to, 'base'.
  """
  @spec match(String.t, [String.t]) :: [String.t]
  def match(base, candidates) do
    is_anagram_of_base? = fn candidate -> anagrams?(base, candidate) end
    candidates
    |> Enum.filter(fn (candidate) -> is_anagram_of_base?.(candidate) end)
  end

  @spec anagrams?(String.t, String.t) :: boolean
  defp anagrams?(base, candidate) do
    sorted = fn (str) -> String.to_char_list(str) |> Enum.sort end

    base_lowercase = String.downcase(base)
    candidate_lowercase = String.downcase(candidate)

    (base_lowercase != candidate_lowercase) and
    (sorted.(base_lowercase) == sorted.(candidate_lowercase))
  end
end
