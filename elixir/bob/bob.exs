defmodule Bob do
  def hey(input) do
    cond do
        String.length(String.lstrip(input)) == 0 -> "Fine. Be that way!"
        String.equivalent?(String.upcase(input), input) and not String.equivalent?(String.downcase(input), input) -> "Whoa, chill out!"
        String.ends_with?(input, "?") -> "Sure."
        true -> "Whatever."
    end
  end
end
