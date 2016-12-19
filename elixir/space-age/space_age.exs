defmodule SpaceAge do
  @type planet :: :mercury | :venus | :earth | :mars | :jupiter
                | :saturn | :uranus | :neptune

  @earth_year_in_seconds 31557600
  @relative_period %{
      earth: 1,
      mercury: 0.2408467,
      venus: 0.61519726,
      earth: 1.0,
      mars: 1.8808158,
      jupiter: 11.862615,
      saturn: 29.447498,
      uranus: 84.016846,
      neptune: 164.79132,
    }

  @doc """
  Return the number of years a person that has lived for 'seconds' seconds is
  aged on 'planet'.
  """
  @spec age_on(planet, pos_integer) :: float
  def age_on(planet, seconds), do: seconds / period(planet)

  defp period(planet), do: @relative_period[planet] * @earth_year_in_seconds
end
